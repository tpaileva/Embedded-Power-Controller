# Processor Board Gen4
Code for the firmware that runs on the Gen4 Power/Processor Boards

## Testing on the Robot
### Start Up
- Connect an HDMI monitor, USB keyboard and mouse to the Ruby
- Login to spot:
  - Username: `ssh costar@Spot#`
  - Password: `costar`
- Turn on hovermap for robots with hovermap (press the button once)
- Make sure the artifact computer (Xavier) is on
- Type `launch-spot` or `launch-husky`, it will open tmux screen
- Open node manager by typing `node_manager`  in Ruby terminal (open a new terminal)
-- If it isn't working, run `source /opt/ros/melodic/setup.bash`
- In `node_manager`
  - Launch the `FiducialCalibrationFromFile` 
  - Press green play button
  - Launch the `Localizer`. At this point all process should be running 
    - Press the play button
  - (Optional) Launch the `Logger` to record logs.  Currently logs everything.

### Connection to Artifact Computer
From the robot’s Ruby - `ssh artifact`

### Shut down the ROS
- In tmux script terminal, CTRL+B+X to exit the tmux script
- Run `cleanup-spot` or `cleanup-husky` (do this every time we want to re-launch launch-spot ..)
