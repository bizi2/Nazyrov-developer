call ndk-build clean
call ndk-build TARGET_LINK=0 NDK_DEBUG=0 CONFIGURATION=StaticRelease
call ndk-build TARGET_LINK=0 NDK_DEBUG=1 CONFIGURATION=StaticDebug
rmdir /s /q libs
rmdir /s /q obj
call ndk-build clean
call ndk-build TARGET_LINK=1 NDK_DEBUG=0 CONFIGURATION=DynamicRelease
call ndk-build TARGET_LINK=1 NDK_DEBUG=1 CONFIGURATION=DynamicDebug
rmdir /s /q libs
rmdir /s /q obj
rem xcopy /y ..\..\..\..\BuildFiles\Android\arm64-v8a\StaticRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.a %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\arm64-v8a\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\arm64-v8a\DynamicRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.so %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\arm64-v8a\DynamicRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\armeabi\StaticRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.a %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\armeabi\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\armeabi\DynamicRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.so %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\armeabi\DynamicRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\armeabi-v7a\StaticRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.a %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\armeabi-v7a\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\armeabi-v7a\DynamicRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.so %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\armeabi-v7a\DynamicRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\mips\StaticRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.a %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\mips\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\mips\DynamicRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.so %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\mips\DynamicRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\mips64\StaticRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.a %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\mips64\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\mips64\DynamicRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.so %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\mips64\DynamicRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\x86\StaticRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.a %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\x86\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\x86\DynamicRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.so %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\x86\DynamicRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\x86_64\StaticRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.a %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\x86_64\StaticRelease\
rem xcopy /y ..\..\..\..\BuildFiles\Android\x86_64\DynamicRelease\libD8D5E0FE0EC64CF98F5FE31BDBDD7F7A.so %ECO_FRAMEWORK%\Eco.SSH1.AP\BuildFiles\Android\x86_64\DynamicRelease\
pause
