#!/bin/bash

# tmux script for checking the Power Board

clear
echo ""
echo "Starting test code for the SubT Power Board"
echo ""


# Start the tmux
SESSION=SubTPowerBoard

# Create the new session
tmux new -s $SESSION -n "PowerBoard" -d

# Split the windows up
tmux split-window -v -t $SESSION:0
tmux split-window -v -t $SESSION:0.1

tmux split-window -h -t $SESSION:0.0
tmux split-window -h -t $SESSION:0.2
tmux split-window -h -t $SESSION:0.4

tmux select-layout tiled

# Send commands
# C-m is the equivalent of hitting enter
# Start htop

# Start mavros
tmux select-pane -t $SESSION:0.0 -T "Messages"
tmux send-keys   -t $SESSION:0.0 "rostopic echo /robot/power_board/msg" C-m

# Echo state from mavros
tmux select-pane -t $SESSION:0.1 -T "Tier 1 Publisher" 
tmux send-keys   -t $SESSION:0.1 "rostopic pub /robot/e_stop/tier1_request std_msgs/Bool \"data: true\""

# Lepton data update rate
tmux select-pane -t $SESSION:0.2 -T "E-Stop" 
tmux send-keys   -t $SESSION:0.2 "rostopic echo /robot/e_stop/status" C-m

# Test scripts
tmux select-pane -t $SESSION:0.3 -T "Rates"
tmux send-keys   -t $SESSION:0.3 "rostopic hz -w 5 /robot/e_stop/status /robot/power_board/status" C-m

# Logging
tmux select-pane -t $SESSION:0.4 -T "Logging"
tmux send-keys   -t $SESSION:0.4 "rosbag record -e \"(.*)e_stop(.*)\" -e \"(.*)power_board(.*)\" -e \"(.*)co2(.*)\" -e \"(.*)comm_dropper(.*)\"" C-m

# kill-session pre-load
tmux select-pane -t $SESSION:0.5 -T "Script Kill"
tmux send-keys   -t $SESSION:0.5 'tmux kill-session'

# Open the session up
tmux -2 attach-session -t $SESSION:0.5

# Need it to run the command << source-file ~/.tmux.conf (from https://www.linode.com/docs/networking/ssh/persistent-terminal-sessions-with-tmux/)>>

# Kill the session
# tmux kill-session