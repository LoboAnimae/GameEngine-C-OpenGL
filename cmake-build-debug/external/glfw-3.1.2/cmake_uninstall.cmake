
if (NOT EXISTS "/home/yagdrassyl/Documents/Code/University/GameEngineArchitecture/Pong-OpenGL/cmake-build-debug/external/glfw-3.1.2/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: \"/home/yagdrassyl/Documents/Code/University/GameEngineArchitecture/Pong-OpenGL/cmake-build-debug/external/glfw-3.1.2/install_manifest.txt\"")
endif()

file(READ "/home/yagdrassyl/Documents/Code/University/GameEngineArchitecture/Pong-OpenGL/cmake-build-debug/external/glfw-3.1.2/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")

foreach (file ${files})
  message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  if (EXISTS "$ENV{DESTDIR}${file}")
    exec_program("/opt/clion-2022.1.3/bin/cmake/linux/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
                 OUTPUT_VARIABLE rm_out
                 RETURN_VALUE rm_retval)
    if (NOT "${rm_retval}" STREQUAL 0)
      MESSAGE(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    endif()
  elseif (IS_SYMLINK "$ENV{DESTDIR}${file}")
    EXEC_PROGRAM("/opt/clion-2022.1.3/bin/cmake/linux/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
                 OUTPUT_VARIABLE rm_out
                 RETURN_VALUE rm_retval)
    if (NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing symlink \"$ENV{DESTDIR}${file}\"")
    endif()
  else()
    message(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
  endif()
endforeach()

