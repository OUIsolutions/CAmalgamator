
local silver_chain_organize_done = false
function silver_chain_organize()
    if silver_chain_organize_done then
        return
    end
    silver_chain_organize_done = true
    darwin.silverchain.generate({
        src = "src",
        project_short_cut = "CAmalgamator",
        tags = { 
            "api_dependencies",
        "api_const",
        "api_type",
        "api_declare",
        "api_define",
        "cli_dependencies",
        "cli_type",
        "cli_globals",
        "cli_declare",
        "cli_define"
    }})
end 