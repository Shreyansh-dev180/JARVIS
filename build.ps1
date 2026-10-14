$sources = @(
    "Manager.cpp",
    "system_automation/temp_cleaner.cpp",
    "browser_automation/youtube_agent.cpp",
    "command_parser/command_parser.cpp"
)

g++ -o jarvis $sources

if($LASTEXITCODE -eq 0){
    Write-Output "Jarvis Compiled Successfully";
}
else{
    Write-Output "Jarvis Compilation Failed";
}