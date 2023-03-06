# Simulink Model Details

Download cpr_vX.zip

Open and run the init_top_level.m
 -->Can choose the data loaded in init by which line is uncommented

Then open top_level_algo.slx (not .slxc)

Under simulation tab change run time to appropriate value

Then run from simulation tab



## Subsystem Notes

 ### Hardware Hiding:
 - Converts raw ADC value to distance in mm, uses low pass filter to limit bit switching

 ### Direction:
 - Determines the direction of distance (pos, zero, or neg)

 ### MinMax:
 - Identifies Local max and Min displaceent during compression

 ### Compression Detection:
 - Identifies a complete compression, counts number of compressions, records duration of compression in seconds
