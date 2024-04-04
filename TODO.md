For all packages in /packages/src

- Create a README.md for each package
- Write a description for each package in the README, that describes the folder structure, and the content of the package
- Test each launch file, and document any launch files with errors (there may be missing packages, which still need to be copied over from /packages_todo/src).
- Write a description about the function of each launch file

For the packages in /packages_todo/src

- copy auna_comm over to /packages/src and try to compile it. If there are any errors, fix dependencies and names in header files.
- Copy over auna_mqtt. Add the commands from auto_setup.sh to the Dockerfile, to install the mqtt dependencies in /home/vscode
- Copy over etsi_its_msgs and try to compile it
