cmake_minimum_required(VERSION 4.2)
project(CLionProjects C)

set(CMAKE_C_STANDARD 17)

add_executable(CLionProjects main.c
        chapter02/11_TestIO.c
        chapter03/24_gotoTest.c
        chapter05/AA_heima.c
        chapter05/AA_AdvancedPointers.c
        chapter05/AA_heima2.c
        chapter05/07_malloc.c
        chapter07/02_StructTest2.c
        chapter07/03_StructTest3.cpp
        chapter08/01_String.c
        chapter08/02_TraverseString.c
        chapter08/03_Traverse.c
        chapter08/04_StringCommonlyFunctions.c
        chapter08/05_userLogin.cpp
        chapter09/01_StructTest.c
        chapter09/01_StructDef.c
        chapter09/02_StructuresAndFunctions.cpp
        chapter09/03_StructureNesting.c
        chapter10/01_UnionTest.c
        chapter10/02_UnionTest.c
        chapter11/01_MemoryDynamicy.c
        chapter11/02_MemoryDynamics.c
        chapter12/01_file.c
        chapter12/02_file_fgetc.c
        chapter12/03_file_fgets.c
        chapter12/04_file_fread.c
)
