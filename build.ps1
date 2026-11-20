$sources = @(
    "Manager.cpp",
    "system_automation/temp_cleaner.cpp",
    "browser_automation/youtube_agent.cpp",
    "browser_modules/fallback_function.cpp",
    "browser_modules/user_browser_detection.cpp",
    "browser_modules/user_browser_launch.cpp",
    "command_parser/command_parser.cpp",
    "browser_automation/google_search.cpp",
    "system_automation/system_info.cpp",
    "system_health_monitor/ram_health.cpp",
    "system_health_monitor/monitor_manager.cpp",
    "system_health_monitor/cpu_health.cpp"
    "authentication_module/authentication_manager.cpp"
    "authentication_module/login_module.cpp"
    "authentication_module/new_account_creation.cpp"

)

$includePaths = @(
    "-Iexternal_libraries/libsodium-win64/include"
)

$libraryPaths = @(
    "-Lexternal_libraries/libsodium-win64/lib"
)

$dependencies = @(
    "-lpdh",
    "-lsodium"
)

g++ -o jarvis $sources $includePaths $libraryPaths $dependencies

#just after compilation capture the result for comparison
$compilationStatus = $LASTEXITCODE

if($compilationStatus -eq 0){
    Write-Output "Jarvis Compiled Successfully";
}
else{
    Write-Output "Jarvis Compilation Failed";
}


#copying dll files in jarvis.exe directory as jarvis will require it 
#because jarvis is compiled using sodium so its dll is needed.

$dllSource = "external_libraries/libsodium-win64/bin/libsodium-26.dll"
$dllDestination = "libsodium-26.dll"

if(!(Test-Path $dllDestination)){

    Copy-Item $dllSource "." -Force
    Write-Output "libsodium-26.dll has been copied to root dir."
}

else{
    Write-Output "libsodium-26.dll already exists."
}