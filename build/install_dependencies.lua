function Install_dependencies()
    local hasher = darwin.dtw.newHasher()
    hasher.digest_folder_by_content("dependencies")
    local TARGET_HASH = "ad254d93a164939bc6c3a9a84451d5195d16142d5149b973433688f09d27af1e"
    if hasher.get_value() == TARGET_HASH then
        return
    end
    local comands = {
        "mkdir -p dependencies",
        "curl -L https://github.com/OUIsolutions/CTextEngine/releases/download/v2.002/CTextEngine.h -o dependencies/CTextEngine.h",
        "curl -L https://github.com/OUIsolutions/DoTheWorld/releases/download/v7.005/doTheWorld.h -o dependencies/doTheWorld.h",
        "curl -L https://github.com/OUIsolutions/Universal-Garbage-Colector/releases/download/v2.003/UniversalGarbage.h -o dependencies/UniversalGarbage.h",
        "curl -L https://github.com/OUIsolutions/C-Cli-Entry/releases/download/0.001/CliEntry.h -o  dependencies/CliEntry.h",
    }
    for _, command in ipairs(comands) do
        os.execute(command)
    end
    local new_hasher = darwin.dtw.newHasher()
    new_hasher.digest_folder_by_content("dependencies")
    print("new hasher is: ", new_hasher.get_value())
end