#!/bin/bash

# Set the workspace directory
WORKSPACE_DIR="/home/vscode/workspace/packages/src/auna_gazebo/worlds"
#!/bin/bash

# List .world files in the workspace directory
world_files=($(find $WORKSPACE_DIR -type f -name "*.world"))

# Check if there are any .world files
if [ ${#world_files[@]} -eq 0 ]; then
  echo "No .world files found in $WORKSPACE_DIR"
  exit 1
fi

# Display .world files with just the base names
echo "Select a .world file:"
select world_file in "${world_files[@]}"; do
  if [ -n "$world_file" ]; then
    echo "Selected .world file: $world_file"
    # Extract the base name without path and extension
    world_name=$(basename "$world_file" .world)
    echo "Running ros2 launch with .world file name: $world_name"
    ros2 launch auna_gazebo gazebo_world.launch.py world_name:="$world_name"
    exit 0
  else
    echo "Invalid selection"
  fi
done
