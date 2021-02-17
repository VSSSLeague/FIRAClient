[![Organization](https://img.shields.io/:Very%20Small%20Size%20Soccer-FIRAClient-333436.svg?logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAADjElEQVQ4jSXS2U/bBQDA8R/rapEB6woUaCljSDnKIdfAMRgtlLa0/HofUDqgG8cKCGTcKMcQNgKyRdlGNiUmSsY0Bvc0X6YxmvhgzOKLjz4sMZq4qItxYVx+fdi/8MlHaDDqsVvN2EUbLpcDv99PRUU5ZWUl6PKzKSzKRZefTUF+Dt99+zV7u/9iNtcAf6LLTUPwOG3091xkeKCX0cFB+i70MBNYQCKRsLP8mLLSQvJ1uRQW5KDL05KlzSAjIx2t9jV2nz1BCAbcDPV1MTs1wgw3eEU4gmN8H1m0BOv4X1RUFHGwe51DNsnSZpCenoZSqSQh4QSVZ8oRmn1O+nsukqw8gW/sFyqrbCSnJBATE01mZgZbWxt88+gBwhGBQ+6h0ajZ/uJTFAo5J09qEDrON+P2iBi8GhJTZOzvPcfnd+Jy2mgw6lGrU3n01Zf8/uRnrK5i/P4q0tJUaDRqTmVqEOAQq83EIavss0ioxcL8zDCDb4bp6GjGbDKgUispyMtCFBv47el9MrWJaLMzKC0pQGgNeZFIoujoaKM95GN6vI+F6WEW5kYZu9xDOOTHYKhHpVby2eZtSopyODj4ldJSHXX6MgSv101MTDRJSQm8PTnExx/dZn1tieX5WQ4PduCuCoeop6AwF7U6ldd1WdTWVmIwnMFkrEQINHtQKOQkJSXw/TMnA70RShtbubEyx8zUAEG/SJPZgEFfzd7eC+qN5zCZTFistdTX1SCsvHuNO3fWiYoSiJUdJXL/KaHzzVxdmGCgt51wWwCvy4pTNJGmVnLs2KuIosjVx/9xurwYYX5+DpUqBZlMilQqoSXoA/aZmujHYq2mMxwk1OKmyWZCoZAjlUoYCRUTHx+LtdGIMDE5gsfjIj4+Frk8nlp9Fd2dzdy6OcdPtPLiYIu2Vjdnq07zz99/0Bvp5PnOQ4IBOwGviBC51ElPTxc5OVoc9kbaO4Iv7xfmUnlWhbFJiyxGQld3mKUfDthePUdvd5BIZ5juCwGElqCXtvYW2tpb8HjtWG31KBRycvNOMTs3gaXRiCAIxMUd54Mf4WicwOKVMSZHI4wMdSE4nFY8Xjs+vxOnw0p1zRskJychVxwnJTWRlJSXcDKZlPffW2X9+jU+XFtmdXGKd2aHEZpEM6LdgtlSh9vVhKlBj1204PfYuTx4iem3BlldmmdzY42Hn3/Cg3sbbG/e5ebyHLdWrvA/5UEMH5awhQgAAAAASUVORK5CYII=)](https://github.com/VSSSLeague) 
![Build](https://github.com/VSSSLeague/FIRAClient/workflows/Build/badge.svg)
[![CodeFactor](https://www.codefactor.io/repository/github/vsssleague/firaclient/badge)](https://www.codefactor.io/repository/github/vsssleague/firaclient)

# FIRAClient

## Introduction
This repository contains a basic example for teams starting in the Very Small Size Soccer category and similar.

This example contains the reception of messages from the automatic Referee and the Fira-Sim simulator used in the Latin American Robotics Competition as well as sending messages to the simulator and to the robots repositioning module.

## Requirements
 * g++ (used v9.3.0)
 * Qt (used version v5.12.8)
 * Qt OpenGL
 * Google protocol buffers (used protoc v3.6.1)
 
## Compilation
Create an folder named `build`, open it and run the command `qmake ..`  
So, after this, run the command `make` and if everything goes ok, the binary will be at the folder `bin` (at the main folder).  

```shell
mkdir build
cd build
qmake ..
make
```

## Important notes
 * Note that this implementation is just a basic model. Teams must make adjustments that address the real need for their strategies.
