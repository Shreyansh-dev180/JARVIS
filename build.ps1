$sources = @(
    "Manager.cpp",
    "system_automation/temp_cleaner.cpp",
    "browser_automation/youtube_agent.cpp",
    "browser_modules/fallback_function.cpp"
    "browser_modules/user_browser_detection.cpp"
    "browser_modules/user_browser_launch.cpp"
    "command_parser/command_parser.cpp"
    "browser_automation/google_search.cpp"
)

g++ -o jarvis $sources

if($LASTEXITCODE -eq 0){
    Write-Output "Jarvis Compiled Successfully";
}
else{
    Write-Output "Jarvis Compilation Failed";
}