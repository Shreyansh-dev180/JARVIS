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
)

$dependencies = @(
    "-lpdh"
)

g++ -o jarvis $sources $dependencies

if($LASTEXITCODE -eq 0){
    Write-Output "Jarvis Compiled Successfully";
}
else{
    Write-Output "Jarvis Compilation Failed";
}