function Install_dependencies()
    local hasher = dtw.newHasher()
    hasher.digest_folder_by_content("dependencies")
    local TARGET_HASH = "bf1f7e84f00fbcee177987c0f8247286ae45de2c04e64cbc1cc997fbeb6a12f6"
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
    local new_hasher = dtw.newHasher()
    new_hasher.digest_folder_by_content("dependencies")
    print("new hasher is: ", new_hasher.get_value())
end