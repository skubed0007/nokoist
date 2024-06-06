### ***Installation for linux***
**MAKE SURE TO RUN IT WITH 'sudo' privladges**


type in the following afer downloading the linux executable:
```sh
cd ~/Downloads    # Assuming the executable is in the Downloads directory
chmod +x ./nokoist_lin    # Make the executable file executable
sudo mkdir -p /usr/bin/nokoist_lin    # Create the directory if it doesn't exist (-p option)
sudo mv ./nokoist_lin /usr/bin/nokoist_lin/nokoist_lin    # Move the executable into the directory with the same name
cd /usr/bin/nokoist_lin    # Navigate to the directory containing the executable
sudo chmod +x nokoist_lin    # Make the symlink executable
sudo ln -s /usr/bin/nokoist_lin/nokoist_lin /usr/bin/nokoist    # Create the symlink
sudo chmod +x /usr/bin/nokoist
```
