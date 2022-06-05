
if (WIN32)

    if (USE_NSIS_TOOLSET)
        # this needs NSIS installed, and available
        set(CPACK_GENERATOR "NSIS") 
        # If this is set to “ON”, then an extra page will appear in the installer 
        # that will allow the user to choose whether the program directory should 
        # be added to the system PATH variable.
        set(CPACK_NSIS_MODIFY_PATH    ON)
        set(CPACK_NSIS_URL_INFO_ABOUT "${PROJECT_URL_INFO}")
        set(CPACK_NSIS_HELP_LINK      "${PROJECT_URL_HELP}")
        set(CPACK_NSIS_INSTALL_ROOT   "C:\\")

        set(CPACK_PACKAGE_INSTALL_DIRECTORY   "user")
        set(CPACK_PACKAGE_NAME                "${PROJECT_NAME}")
        set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_DESCRIPTION}")
        set(CPACK_PACKAGE_VERSION             "${PROJECT_VERSION}")

    endif ()
    set(CPACK_SOURCE_GENERATOR "ZIP")

else ()

    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_NAME           "${PROJECT_NAME}")
    set(CPACK_DEBIAN_PACKAGE_SOURCE         "${PROJECT_NAME}")
    set(CPACK_DEBIAN_PACKAGE_VERSION        "${PROJECT_VERSION}")
    set(CPACK_DEBIAN_PACKAGE_SECTION        "${DEBPACK_SECTION}")
    set(CPACK_DEBIAN_PACKAGE_HOMEPAGE       "${PROJECT_URL}")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS        "${DEBPACK_REQUIRES}")
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY   "${PROJECT_COMMENT}")
    set(CPACK_DEBIAN_PACKAGE_DESCRIPTION    "${PROJECT_DESCRIPTION}")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER     "${PROJECT_AUTHOR}") #required

    set(CPACK_SOURCE_GENERATOR "TGZ")

endif ()
set(CPACK_PACKAGE_VENDOR           "${PROJECT_VENDOR}")
set(CPACK_PACKAGE_FILE_NAME        "${PROJECT_NAME}-${PROJECT_VERSION}_${DEBFILE_ARCH}")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${PROJECT_NAME}-${PROJECT_VERSION}")
set(CPACK_SOURCE_IGNORE_FILES      "/build/;/.bzr/;/.bzrignore;/.git/;/.gitignore;~$;${CPACK_SOURCE_IGNORE_FILES}")

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README  "${CMAKE_SOURCE_DIR}/README.md")

include(CPack)

