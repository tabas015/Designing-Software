# Lab02 - Web Sockets

*(Due **Thursday**, February 3rd @ 11:59 PM)*

<br>

## What you'll learn today:
<ol>
  <li>  How to develop in a supported linux environment (Docker / CSE Lab Machines / VOLE / SSH)
  <li>  How to clone a repository using Git
  <li>  How to build and run a C++ program using a Makefile
  <li>  An introduction to passing and using JSON between Javascript and C++
</ol>

<br>

## Building the Development Environment

<hr>
  **The primary goal of this lab is for you to setup your development environment for front-end and back-end development.**
<hr>

In this lab we are aiming to understand the connection between the front-end and back-end development using a web sockets library.
We will also investigate the Model View Controller (MVC) pattern.  You will get this lab checked off by your lab section TAs similar to Lab 01.

## Peparing for the lab

### Download Git [Windows Only]

You can download git [here](https://git-scm.com/). Follow the onscreen instructions to install it wherever you wish.
Unless you are using WSL2 (see below), you should run all commands listed below inside of `git bash`. 
After installing git, you should be able to launch `git bash` like any other program, either creating a shortcut on your desktop/toolbar or opening it from your programs menu.

### Choosing your development environment

In this class we support the following linux development environments:

 * __Docker__ on personal machines
 * __CSE Lab Machines__
 * __VOLE / VOLE3D__
 * __SSH__

Students may choose which computer/OS they would like to use for working on labs and the project. The lab guides are mainly developed for Linux, but Windows is supported as well through Docker. You may use the computers in lab, your own personal machine, [department computers](https://cse.umn.edu/cseit/classrooms-labs#cs) via SSH, or [Vole3D](https://cse.umn.edu/cseit/self-help-guides/virtual-online-linux-environment-vole). If you decide to use any UMN resource, you will need to login with your CSE Lab account. If you need to register for an account or are unsure if your account is still active, [click here](https://wwws.cs.umn.edu/account-management/). A benefit of using U of M machines is your home directory will be synced across any computer you log into. This means you can start working on the assignment from a lab computer in person, then continue working at home via Vole or a department computer. Please note that future labs and projects for this class will have visualizations and graphics, so project development purely over SSH is not recommended.

For additional information about Linux, see
https://tutorials.ubuntu.com/tutorial/command-line-for-beginners#2 and/or
https://www.tutorialspoint.com/unix/index.htm

### Docker Instructions [for personal machines]

We recommend using Docker when developing on your own personal machine.  Here are the steps on how to setup docker

#### Docker Pre-requisites
  * Windows 10 Home
    * Install [wsl2 and Ubuntu](https://www.youtube.com/watch?v=ilKQHAFeQR0&list=RDCMUCzLbHrU7U3cUDNQWWAqjceA&start_radio=1&t=7) and [Windows 10 Doc](https://docs.microsoft.com/en-us/windows/wsl/install-manual)
    * For [Windows 11](https://docs.microsoft.com/en-us/windows/wsl/install) 
  * Install [Docker Desktop](https://www.docker.com/products/docker-desktop) from [Docker Hub](https://hub.docker.com/)
  * Linux
    * Use [docker group instead of sudo](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-18-04)

#### Getting Started with Docker ([after cloning the repository](#download-the-repository))

On Windows use the "Git Bash" terminal.

1. Build docker image
    ```bash
    bin/build-env.sh
    ```
2. Run docker image
    ```bash
    #Usage bin/run-env.sh <port - optional(default 8081)>
    bin/run-env.sh
    ```

### shared-upstream: The Read-Only 3081 Course Repository

Computer Science courses are setup for github by first establishing a GitHub organization (e.g. umn-csci-3081-s22), as well as a read-only course repository (e.g. shared-upstream). Course materials will be distributed via the read-only repository, which will eventually be merged into the main branch of your repository.

Open your browser and enter the following URL:

https://github.umn.edu/umn-csci-3081-s22/shared-upstream

Take some time and poke around in this repository, especially if you have never seen the GitHub interface before. If you have questions about the interface, search for answers online. DuckDuckGo, Google and other search engines will be your friend during this class. In particular, StackOverflow is a great resource - be careful that not all answers on the site are perfect though.

## Understanding the Model View Controller Pattern

In Lab 01, we created the front-end HTML / CSS code (the View).  In this lab we will provide example javascript code that allows us to
talk to a C++ back-end using web sockets.  The goal is to first get everything compiled and running.  You will use examples in the code both in C++
and Javascript to connect the View with the Model.

First, let's take a look at the C++ code here: https://github.umn.edu/umn-csci-3081-s22/shared-upstream/blob/main/labs/lab02-web-sockets/transit_service.cc

Notice that we have several classes.  First, we have the [IController](https://github.umn.edu/umn-csci-3081-s22/shared-upstream/blob/main/labs/lab02-web-sockets/transit_service.cc#L8) class, which allows us to talk to the controller from the model.  Second, we have the [SimulationModel](https://github.umn.edu/umn-csci-3081-s22/shared-upstream/blob/main/labs/lab02-web-sockets/transit_service.cc#L18) class, which is the model.  Most of our work thought the class will be done within the model's subsystem.  Third, we have the [TransitService](https://github.umn.edu/umn-csci-3081-s22/shared-upstream/blob/main/labs/lab02-web-sockets/transit_service.cc#L58), which is the Web Sockets API (also the "concrete" controller - inheriting from the IController).  At this point you do not need to worry about the C++ code or the inheritance structure.  For now you can just focus on which subsystem each class represents.  Remember that the model talks to the controller, and the controller talks with the view.

For example, look at the [ScheduleTrip(...)](https://github.umn.edu/umn-csci-3081-s22/shared-upstream/blob/main/labs/lab02-web-sockets/transit_service.cc#L33) function in the SimulationModel class.  At the end of the function, it sends an event to the view through the controller.  Notice also that inside the [ReceiveCommand(...)](https://github.umn.edu/umn-csci-3081-s22/shared-upstream/blob/main/labs/lab02-web-sockets/transit_service.cc#L63) function in the TransitService, the controller calls functions inside the model.  If we want to add new communication commands we would edit the ReceiveCommand(...) function.

The [web](https://github.umn.edu/umn-csci-3081-s22/shared-upstream/tree/main/labs/lab02-web-sockets/web) folder contains our view:
 * [index.html](https://github.umn.edu/umn-csci-3081-s22/shared-upstream/blob/main/labs/lab02-web-sockets/web/index.html) - contains a simple view that sends a ping command to the controller and prints the response.
 * [schedule.html](https://github.umn.edu/umn-csci-3081-s22/shared-upstream/blob/main/labs/lab02-web-sockets/web/schedule.html) - is the result from Lab 01 with additional JQuery commands to handle events from the UI.  Take a look at how click events are wired together with the HTML.

## Building and Running the program

To build and run the program follow the steps below in one of the approved development environments (Docker / CSE Lab Machines / VOLE / SSH):

### Download the repository

  Clone the repository to a local folder using git:
  ```bash
  % mkdir -p csci3081
  % cd csci3081
  % git clone https://github.umn.edu/umn-csci-3081-s22/shared-upstream.git
  ```
### Build the application

Change to the lab directory and build using `make`
  ```bash
  % cd shared-upstream/lab/lab02-web-sockets
  % make
  ```
  
This will create a build directory and build the application.  For now you do not need to worry about what is going on in the Makefile.  In future labs we will discuss this in more detail.

### Run the application

From the lab directory, run the program by passing in a port and the web directory to specify the view:

  ```bash
  % cd shared-upstream/lab/lab02-web-sockets
  % build/bin/transit_service 8081 web
  ```
Run the view by navigating to http://127.0.0.1:8081

You should see a text box and a button.  Type into the box and press the button.  Notice that two things happen:
 1. You will see the response under the text box on the view.
 2. You will see the command on the command line from the transit_service
 
**Check Off** - If you see the two items above, you can check off this section of the lab.
 
### Run the schedular

Now navigate to a different view using the same Transit Service API.  Navigate to http://127.0.0.1:8081/schedule.html

This modified view from Lab 01 uses Javascript to interactively schedule trips.  You can now enter a name, click on multiple locations on the map, and schedule a trip.  Notice that when you schedule a trip a command is run in the back-end.  This is called via the api.sendCommand(...) in the view here: https://github.umn.edu/umn-csci-3081-s22/shared-upstream/blob/main/labs/lab02-web-sockets/web/schedule.html#L85.

Your task is to add the api command detailed in the first `TODO:` comments in schedule.html.  The first command should tell the controller to call the model's ScheduleTrip(...) command.  You will need to edit the JSON in the command so that the trip is scheduled in the model and it is reported in the [api.onmessage(...)](https://github.umn.edu/umn-csci-3081-s22/shared-upstream/blob/main/labs/lab02-web-sockets/web/schedule.html#L69) method.  If done correctly, you will see a blue popup (see original project demo) that says "Your trip is scheduled!"

__Hint:__ Understand how the controller connects to the model in the [ReceiveCommand(...)](https://github.umn.edu/umn-csci-3081-s22/shared-upstream/blob/main/labs/lab02-web-sockets/transit_service.cc#L63) function.  Also, take a look at what JSON values should be available within the JSON object in the [ScheduleTrip(...)](https://github.umn.edu/umn-csci-3081-s22/shared-upstream/blob/main/labs/lab02-web-sockets/transit_service.cc#L33) function.

**Check Off** - If you see the popup, you can get this portion of the lab checked off.

**Challenge** - Do the second `TODO:` item where you call the model's CreateEntity(...) function. 

## Lab Completion

THIS LAB IS COMPLETE.

Congratulations!
