# vlm-krakenx-daemon
Daemon for controlling NZXT Kraken series X52/X62/X72 under Linux distributions.
### Prerequisites
**lm-sensors**
> https://github.com/lm-sensors/lm-sensors
>
**krakenx** 
>https://github.com/KsenijaS/krakenx
>
### Build
>Run cmake from project root with the desired output path
>
### Installation
**Obtain binary**
>Build or use binary from 'pre-built-binary' folder
>
**Create directory**
>sudo mkdir /etc/vlm-krakenx
>
**Copy binary**
>sudo cp <path-to-binary> /etc/vlm-krakenx/
>
**Change permissions**
>sudo chmod u+x /etc/vlm-krakenx/vlm-krakenx-daemon
>
**Create service**
>sudo touch /etc/systemd/system/vlm-krakenx-service.service
>
**Open service**
>sudo nano /etc/systemd/system/vlm-krakenx-service.service
>
**Edit service**
>[Unit]
>Description=NZXT Kraken Daemon
>[Service]
>ExecStart=/etc/vlm-krakenx/vlm-krakenx-daemon
>[Install]
>WantedBy=multi-user.target
>
**Start service**
>sudo systemctl start vlm-krakenx-service.service
>
**Enable service**
>sudo systemctl enable vlm-krakenx-service.service
>
