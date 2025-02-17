---@class Darwin
darwin = darwin


function main()
    local possible_test = darwin.argv.get_next_unused()

    if possible_test == "test_container" then
        local container_name = darwin.argv.get_next_unused()
        if container_name == nil then
            print("Please provide a container name")
            return
        end
        os.execute("mkdir -p release")
        local image = darwin.ship.create_machine(container_name .. ":latest")
        image.provider = CONTANIZER

        image.start({
            flags = { "-it" },
            volumes = {
                { "./release", "/release" },
            },
        })

        return
    end
    Install_dependencies()
    local build_funcs = create_build_funcs()


    darwin.dtw.remove_any("release")
    darwin.dtw.remove_any(".cache")
    local i = 1
    for name, buld_lambda in pairs(build_funcs) do
        if darwin.argv.one_of_args_exist(name) then
            print("\n=========================================================================================")
            print("\tstarted of build:", i, "\n")
            buld_lambda()
            print("\n\tA build [" .. i .. "] finished")
            print("=========================================================================================\n\n")
            i = i + 1
        end
    end
end
