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
tmux split-window -h -t $SESSION:0.0

tmux split-window -h -t $SESSION:0.3
tmux split-window -h -t $SESSION:0.3

tmux split-window -h -t $SESSION:0.6
tmux split-window -h -t $SESSION:0.6
tmux select-layout tiled

# Send commands
# C-m is the equivalent of hitting enter
# Start htop
tmux select-pane -t $SESSION:0.0 -T "System Monitor" 
tmux send-keys   -t $SESSION:0.0 'htop' C-m

# Start rosserial
tmux select-pane -t $SESSION:0.3 -T "rosserial" 
tmux send-keys   -t $SESSION:0.3 "roslaunch powerBoard.launch" C-m   
sleep 7

# Start mavlink router
tmux select-pane -t $SESSION:0.6 -T "Fault Log" 
tmux send-keys   -t $SESSION:0.6 "rostopic echo /robot/power_board/fault_log" C-m   

# Start mavros
tmux select-pane -t $SESSION:0.4 -T "Messages"
tmux send-keys   -t $SESSION:0.4 "rostopic echo /robot/power_board/msg" C-m

# Echo state from mavros
tmux select-pane -t $SESSION:0.5 -T "Tier 1" 
tmux send-keys   -t $SESSION:0.5 "rostopic pub /robot/e_stop/tier1_request std_msgs/Bool \"data: true\""

# Use mavproxy to see what's going on
tmux select-pane -t $SESSION:0.1 -T "Status" 
tmux send-keys   -t $SESSION:0.1 "rostopic echo /robot/power_board/status" C-m

# Lepton data update rate
tmux select-pane -t $SESSION:0.2 -T "E-Stop" 
tmux send-keys   -t $SESSION:0.2 "rostopic echo /robot/e_stop/status" C-m

# Test scripts
tmux select-pane -t $SESSION:0.7 -T "Rates"
tmux send-keys   -t $SESSION:0.7 "rostopic hz -w 5 /robot/e_stop/status /robot/power_board/status /robot/power_board/fault_log" C-m

# kill-session pre-load
tmux select-pane -t $SESSION:0.8 -T "Script Kill"
tmux send-keys   -t $SESSION:0.8 'tmux kill-session'

# Open the session up
tmux -2 attach-session -t $SESSION:0.8

# Need it to run the command << source-file ~/.tmux.conf (from https://www.linode.com/docs/networking/ssh/persistent-terminal-sessions-with-tmux/)>>

# Kill the session
# tmux kill-session