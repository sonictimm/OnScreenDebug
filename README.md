# OnScreenDebug
On-Screen Debugging Tool for Unreal Engine 5.01

Call "SetDebugStat" to update a statistic
All statistics show up on-screen, and are replaced with updated versions of themselves
Each statistic must have a unique name and a value.  Descriptions are optional.

Meant for quick & Dirty debugging.
Especially useful when you need to play the game while keeping a close eye on a value that is constantly changing, such as velocity of a physics-based item.
I don't recommend shipping a game with any calls to SetDebugStat still in place.  
