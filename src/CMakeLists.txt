project(src)

set(HEADER_FILES
        Node.h
        RBTree.h
        )

set(SOURCE_FILES
        Node.cpp
        RBTree.cpp
        Table.cpp Table.h Person.h)

add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})