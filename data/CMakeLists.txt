project(data)

set(data_RCS icons/icons.qrc i18n/i18n.qrc)
set(data_TRS
  i18n/lugdulov_fr.ts
  i18n/lugdulov_cs.ts
)
set_source_files_properties(${data_TRS} PROPERTIES OUTPUT_LOCATION ${data_SOURCE_DIR}/i18n)

qt4_add_translation(QM_FILES ${data_TRS})
qt4_add_resources(RC_SRCS ${data_RCS})

add_library(lugdulov_data STATIC
  ${QM_FILES}
  ${RC_SRCS}
)