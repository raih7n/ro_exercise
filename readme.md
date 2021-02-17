# Ro Exercise

### Technical interview exercise/project for Ro

given an input of medications, this program will detected any interactions between as determined by interactions.json

Sample input

	ipecac valaciclovir clobazam sildenafil

Sample output:
~~~text
[warning] 4 conflict(s) detected!
[warning] sildenafil will have a moderate interaction with clobazam. The metabolism of Sildenafil can be decreased when combined with Clobazam.
[warning] valaciclovir will have a moderate interaction with ipecac. Valaciclovir may decrease the excretion rate of Ipecac which could result in a higher serum level.
[warning] sildenafil will have a moderate interaction with clobazam. The metabolism of Sildenafil can be decreased when combined with Clobazam.
[warning] valaciclovir will have a moderate interaction with ipecac. Valaciclovir may decrease the excretion rate of Ipecac which could result in a higher serum level.
~~~

## Credits
The following are used without modification. Credits to their authors. Libraries can be installed via vcpkg or your prefered package manager
- [RapidJSON][github.rapidjson]  
A JSON parser and generator for C++  
- [spdlog][github.spdlog]   
Fast C++ logging library

[//]: # (Hyperlink IDs)
[github.rapidjson]: https://github.com/Tencent/rapidjson
[github.spdlog]: https://github.com/gabime/spdlog