local alpine_static_build_done = false

function alpine_static_build()
    if alpine_static_build_done then
        return
    end
    alpine_static_build_done = true
    os.execute("mkdir -p release")

    local image = darwin.ship.create_machine("alpine:latest")
    image.provider = CONTANIZER
    image.add_comptime_command("apk update")
    image.add_comptime_command("apk add --no-cache gcc musl-dev curl")

    image.start({
        volumes = {
            { "./release", "/release" },
            { "./src",     "/src" }

        },
        command = "gcc --static /src/main.c -o /release/alpine_static_bin.out"

    })
end
