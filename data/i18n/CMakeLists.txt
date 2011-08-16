project(translations)

set(translations_TSS
  lugdulov_fr.ts
  lugdulov_cs.ts
)

set_source_files_properties(${lugdulov_TSS} PROPERTIES OUTPUT_LOCATION ${translation_SOURCE_DIR}/i18n)

_qt4_add_translation(TS_SRCS ${lugdulov_TRS})

add_convenience_library(translations ${TS_SRCS})
