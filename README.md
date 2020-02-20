# Airport-Runway-Simmulation

This is  a simulation program for a small airport that has only one runway. There will be a queue of planes waiting to land and a
queue of planes waiting to take off. However, only one plane can use the runway at a time. So there can be only one takeoff or one landing in progress at anyone time. We will assume that all takeoffs take the sameamount of time.We will assume that all landings take thesame amount of time, although this does not need to be the same as the takeoff time.We will assume that planes arrive for landing at random times, but with a specified probability of a plane arriving during any given minute. Similarly,we will  assume that planes arrive at the takeoff queue at random times, but with a (possibly different) specified probability of a departure.

(Despite the fact that takeoffs and landings are scheduled, delays make this a reasonable assumption.) Since it is more expensive and more dangerous to keep a plane waiting to land than it is to keep a plane waiting to take off, landings will have priority over takeoffs. Thus, as long as some plane is waiting to land, no plane can take off.

This simulation can be used, among other things, for deciding when the air traffic has become so heavy that a second runway must be built. Hence, the simulation will simulate conditions that would be a disaster, in which planes crash because they run out of fuel while waiting too long in the landing queue.We will assume all planes can remain in the queue the same amount of time before they run out of fuel. If a plane runs out of fuel, the fact that the plane crashed is recorded, that plane is discarded, and the next plane is processed.

To run this simualtion click here: https://airport-runway-simulation.anjolatopebabal.repl.run/
