# ![](https://github.com/sauerduels/remod-sauerbraten/blob/master/src/res/remod.png) Remod

Lightweight crossplatform sauerbraten server mod.

The goal of project is create lightweight crossplatform (FreeBSD, Linux, Windows and others) mod for replacement of official sauerbraten server.

Nightly builds (Linux and win32 packages) available here: http://remod.butchers.su/.

## Download
  * Latest development version: https://github.com/sauerduels/remod-sauerbraten/releases
  * GIT repository: https://github.com/sauerduels/remod-sauerbraten

## Installation notes and some guides
```
git clone https://github.com/sauerduels/remod-sauerbraten.git
cd remod-sauerbraten
git submodule init
git submodule update
cd src
make
```
  * Check our [wiki page](https://github.com/vasyahuyasa/remod-sauerbraten/wiki/Installation)

## Implemented features
  * server side cubescript
  * remote control, access to serverside cubescript (via tcp, udp and netcat)
  * new cubescript functions
  * GeoIP support
  * IRC bot
  * cubescript events
  * user #commands
  * irc bot user commands
  * save and load maps to local file system in coopedit mode
  * database (sqlite3, mysql)

## Work in progress
  * users system
  * scoreboard
  * anticheat

## Supported platforms
  * Mac (cmake, Xcode)
  * FreeBSD 
  * Linux
  * Windows

## Contacts
  * SauerDuels: [Origin](https://github.com/AngrySnout), [Frosty](https://github.com/vaqfrosty)
  * [SauerDuels on Discord](https://discord.gg/FTSjNfz)
  * remod: [degrave](https://github.com/vasyahuyasa), [^o_o^](https://github.com/rmhmlhr)
  * IRC: irc://irc.gamesurge.net/rb
