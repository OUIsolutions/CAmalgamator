local windows_build_done = false
function windowsi32_build()
    if windows_build_done then
        return
    end
    windows_build_done = true
    silver_chain_organize()

    os.execute("mkdir -p release")

    local image = darwin.ship.create_machine("debian:latest")
    image.provider = CONTANIZER
    image.add_comptime_command("apt-get update")
    image.add_comptime_command("apt-get -y install mingw-w64")

    image.start({
        volumes = {
            { "./release", "/release" },
            { "./src",     "/src" },
            { "./dependencies",     "/dependencies" }
        },
        command = "i686-w64-mingw32-gcc --static /src/cli/main.c -o /release/windowsi32.exe"
    })
end
