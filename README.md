# Amalgamator
A C amalgamator cli to join all files in one, build to be rich in features
and also provide a api for you to use in your building programs


# Cli Usage

to use the  cli, just clone the amalgamated c code
```shell
curl -L https://github.com/OUIsolutions/CAmalgamator/releases/download/0.001/CAmalgamator.c  -o CAmalgamator.c
```
then compile the c file with
```shell

```


## Flags

| Flag | Description | Default |
|------|-------------|---------|
| -s, --src | The project folder (required) | - |
| -i, --importdir | The directory to be used for saving imports | imports |
| -t, --tags | The tags to be used (required) | - |
| -p, --project_short_cut | The project shortcut to be used in #ifndef properties | silverchain |
| -m, --implement_main | true or false to implement the main function | false |
| -n, --main_name | The name of the main function | main.c or main.cpp |
| -p, --main_path | The path of the main function | undefined |
| -h, --help | Shows the help message | - |
| -w, --watch | Watch the project files and rebuild if they change | - |
| -s, --sleep_time | The time to sleep between each check (default: 0) | - |
