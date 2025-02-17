local alreay_amalamated_done = false
function amalgamation_build()
    if alreay_amalamated_done then
        return
    end
    alreay_amalamated_done = true

    local amalgamation_result = darwin.camalgamator.generate_amalgamation("src/main.c")
    darwin.dtw.write_file("release/amalgamation.c", amalgamation_result)
end
