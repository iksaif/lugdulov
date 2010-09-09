#!/usr/bin/env python

import os, sys, re

plugins = [
    {'name' : 'austria', 'Name' : 'Austria', 'NAME' : 'AUSTRIA', 'description' : 'Austria'},
    {'name' : 'lower-austria', 'Name' : 'LowerAustria', 'NAME' : 'LOWER_AUSTRIA', 'description' : 'Lower Austria'},
    {'name' : 'switzerland', 'Name' : 'Switzerland', 'NAME' : 'SWITZERLAND', 'description' : 'Switzerland'},
    {'name' : 'germany', 'Name' : 'Germany', 'NAME' : 'GERMANY', 'description' : 'Germany'},
    {'name' : 'latvia', 'Name' : 'Latvia', 'NAME' : 'LATVIA', 'description' : 'Latvia'},
    {'name' : 'new-zealand', 'Name' : 'NewZealand', 'NAME' : 'NEW_ZEALAND', 'description' : 'New-Zealand'},
    {'name' : 'united-kingdom', 'Name' : 'UnitedKingdom', 'NAME' : 'UNITED_KINGDOM', 'description' : 'United-Kingdom'},
    {'name' : 'canada', 'Name' : 'Canada', 'NAME' : 'CANADA', 'description' : 'Canada'}
]

def gen_common(data, conf):
    data = data.replace("<name>", conf['name'])
    data = data.replace("<Name>", conf['Name'])
    data = data.replace("<NAME>", conf['NAME'])
    return data

def write_file(conf, file, data):
    open("../../plugins/" + conf['name'] + "/" + file, 'w').write(data)

def gen_cmake(conf):
    data = open('CMakeLists.txt').read()
    data = gen_common(data, conf)
    data = data.replace("<Headers>", '\n  '.join(conf['headers']))
    data = data.replace("<Sources>", '\n  '.join(conf['sources']))
    write_file(conf, 'CMakeLists.txt', data)

def gen_factory_cpp(conf):
    data = open('factory.cpp').read()
    data = gen_common(data, conf)
    headers = ""
    plugins = ""
    for header in conf['headers']:
        d = open("../../plugins/" + conf['name'] + "/" + header).read()
        name = re.search(r"class (.*) :", d).groups()[0]
        headers += '#include "' + header + '"\n'
        plugins += "  ret << new " + name + "(parent);\n"
    data = data.replace("<IncludeHeaders>", headers)
    data = data.replace("<Plugins>", plugins)
    data = data.replace("<Descr>", conf['description'] + "Networks")
    write_file(conf, 'factory.cpp', data)

def gen_factory_header(conf):
    data = open('factory.h').read()
    data = gen_common(data, conf)
    write_file(conf, 'factory.h', data)

def gen_pro(conf):
    data = open('tpl.pro').read()
    data = gen_common(data, conf)
    data = data.replace("<Headers>", ' \\\n\t'.join(conf['headers']))
    data = data.replace("<Sources>", ' \\\n\t'.join(conf['sources']))

    write_file(conf, conf['name'] + ".pro", data)

def gen_qrc(conf):
    data = open('tpl.qrc').read()
    data = gen_common(data, conf)
    write_file(conf, conf['name'] + ".qrc", data)

def main():
    for plugin in plugins:
        if plugin['name'] not in sys.argv:
            continue
        files = os.listdir("../../plugins/" + plugin['name'])
        headers = [header for header in files if header.endswith(".h") and header != "factory.h" and not header.endswith("_p.h")]
        sources = [source for source in files if source.endswith(".cpp") and source != "factory.cpp"]
        plugin['headers'] = headers
        plugin['sources'] = sources
        gen_cmake(plugin)
        gen_pro(plugin)
        gen_qrc(plugin)
        gen_factory_cpp(plugin)
        gen_factory_header(plugin)

if __name__ == '__main__':
    main()

# scan .h (skip factory.h)
# CMakeLists.txt
# factory.cpp
# factory.h
# tpl.pro
# tpl.qrc

