# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "G:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "G:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug"

# Include any dependencies generated for this target.
include RestLib\CMakeFiles\RestLib.dir\depend.make

# Include the progress variables for this target.
include RestLib\CMakeFiles\RestLib.dir\progress.make

# Include the compile flags for this target's objects.
include RestLib\CMakeFiles\RestLib.dir\flags.make

RestLib\CMakeFiles\RestLib.dir\Kitchen.cpp.obj: RestLib\CMakeFiles\RestLib.dir\flags.make
RestLib\CMakeFiles\RestLib.dir\Kitchen.cpp.obj: ..\RestLib\Kitchen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object RestLib/CMakeFiles/RestLib.dir/Kitchen.cpp.obj"
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\RestLib"
	C:\PROGRA~2\MICROS~4\2019\ENTERP~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RestLib.dir\Kitchen.cpp.obj /FdCMakeFiles\RestLib.dir\RestLib.pdb /FS -c "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\RestLib\Kitchen.cpp"
<<
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug"

RestLib\CMakeFiles\RestLib.dir\Kitchen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RestLib.dir/Kitchen.cpp.i"
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\RestLib"
	C:\PROGRA~2\MICROS~4\2019\ENTERP~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\RestLib.dir\Kitchen.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\RestLib\Kitchen.cpp"
<<
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug"

RestLib\CMakeFiles\RestLib.dir\Kitchen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RestLib.dir/Kitchen.cpp.s"
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\RestLib"
	C:\PROGRA~2\MICROS~4\2019\ENTERP~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RestLib.dir\Kitchen.cpp.s /c "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\RestLib\Kitchen.cpp"
<<
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug"

RestLib\CMakeFiles\RestLib.dir\test.cpp.obj: RestLib\CMakeFiles\RestLib.dir\flags.make
RestLib\CMakeFiles\RestLib.dir\test.cpp.obj: ..\RestLib\test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object RestLib/CMakeFiles/RestLib.dir/test.cpp.obj"
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\RestLib"
	C:\PROGRA~2\MICROS~4\2019\ENTERP~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RestLib.dir\test.cpp.obj /FdCMakeFiles\RestLib.dir\RestLib.pdb /FS -c "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\RestLib\test.cpp"
<<
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug"

RestLib\CMakeFiles\RestLib.dir\test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RestLib.dir/test.cpp.i"
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\RestLib"
	C:\PROGRA~2\MICROS~4\2019\ENTERP~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\RestLib.dir\test.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\RestLib\test.cpp"
<<
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug"

RestLib\CMakeFiles\RestLib.dir\test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RestLib.dir/test.cpp.s"
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\RestLib"
	C:\PROGRA~2\MICROS~4\2019\ENTERP~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RestLib.dir\test.cpp.s /c "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\RestLib\test.cpp"
<<
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug"

# Object files for target RestLib
RestLib_OBJECTS = \
"CMakeFiles\RestLib.dir\Kitchen.cpp.obj" \
"CMakeFiles\RestLib.dir\test.cpp.obj"

# External object files for target RestLib
RestLib_EXTERNAL_OBJECTS =

RestLib\RestLib.lib: RestLib\CMakeFiles\RestLib.dir\Kitchen.cpp.obj
RestLib\RestLib.lib: RestLib\CMakeFiles\RestLib.dir\test.cpp.obj
RestLib\RestLib.lib: RestLib\CMakeFiles\RestLib.dir\build.make
RestLib\RestLib.lib: RestLib\CMakeFiles\RestLib.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library RestLib.lib"
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\RestLib"
	$(CMAKE_COMMAND) -P CMakeFiles\RestLib.dir\cmake_clean_target.cmake
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug"
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\RestLib"
	C:\PROGRA~2\MICROS~4\2019\ENTERP~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\lib.exe /nologo /machine:X86 /out:RestLib.lib @CMakeFiles\RestLib.dir\objects1.rsp 
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug"

# Rule to build all files generated by this target.
RestLib\CMakeFiles\RestLib.dir\build: RestLib\RestLib.lib

.PHONY : RestLib\CMakeFiles\RestLib.dir\build

RestLib\CMakeFiles\RestLib.dir\clean:
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\RestLib"
	$(CMAKE_COMMAND) -P CMakeFiles\RestLib.dir\cmake_clean.cmake
	cd "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug"
.PHONY : RestLib\CMakeFiles\RestLib.dir\clean

RestLib\CMakeFiles\RestLib.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant" "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\RestLib" "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug" "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\RestLib" "G:\Dokumente\Fachhochschule\6. Semester\PIC_Programmieren in C++\Labor\Restaurant\cmake-build-debug\RestLib\CMakeFiles\RestLib.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : RestLib\CMakeFiles\RestLib.dir\depend

