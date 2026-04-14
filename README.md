# UDF_demo
Activities to learn User-Defined Functions (UDFs) in Ansys Fluent. This repository contains lecture slides, Ansys UDF guide, a zip folder containing meshed channel flow geometry, and three UDFs to run a series of example problems simulating Poiseuille flow heated by a laser,

### Part 0
Use the provided mesh to simulate channel flow. Use water-liquid from the Fluent library. Define a constant uniform inlet velocity of 0.001 m/s. Use the laminar viscous laminar model. The flow will develop through the length of the domain and form a parabolic velocity profile.

### Part 1
Use the `inletProfile.c` UDF to define the inlet as fully developed flow.

### Part 2
Use the `heatSource.c` UDF to add a 2D Gaussian heat source simulating the heat source. 

### Part 3
Use the `viscosityTemp.c` UDF to make viscosity an Arrhenius-type function of temperature. Plot the outlet velocity profile and compare with the analytical solution for part 0. Note the asymmetric flow profile due to laser heating.
