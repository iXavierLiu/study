# _setup_project_env(project_name)
macro(_setup_project_env)
    # for project name
    set("_PARRENT_PROJECT_NAME" ${PROJECT_NAME})
    set("_CURRENT_PROJECT_NAME" ${ARGV0})
    if("${_PARRENT_PROJECT_NAME}" STREQUAL "")
        set("_PROJECT_NAME" ${_CURRENT_PROJECT_NAME})
    else()
        set("_PROJECT_NAME" ${_PARRENT_PROJECT_NAME}_${_CURRENT_PROJECT_NAME})
    endif()

    # for namespace
    if("${_PROJECT_NAMESPACE}" STREQUAL "")
        set("_PROJECT_NAMESPACE" ${_CURRENT_PROJECT_NAME})
    else()
        set("_PARRENT_NAMESPACE" ${_PROJECT_NAMESPACE})
        set("_PROJECT_NAMESPACE" ${_PARRENT_NAMESPACE}::${_CURRENT_PROJECT_NAME})
    endif()
endmacro(_setup_project_env)

function(_test)
    message("==============")
    message("_PARRENT_PROJECT_NAME " ${_PARRENT_PROJECT_NAME})
    message("_CURRENT_PROJECT_NAME " ${_CURRENT_PROJECT_NAME})
    message("_PROJECT_NAME " ${_PROJECT_NAME})

    message("_PARRENT_NAMESPACE " ${_PARRENT_NAMESPACE})
    message("_PROJECT_NAMESPACE " ${_PROJECT_NAMESPACE})
endfunction(_test)
