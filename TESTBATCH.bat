ECHO Testing Again
move $(ProjectDir)x64\Debug\*.obj temp
lib /OUT:"$(TargetPath).lib" $(ProjectDir)x64\Debug\*.obj


