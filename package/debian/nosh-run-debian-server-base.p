# vim: set filetype=sh:
# service list
# common targets, services, and sockets
service_with_dedicated_logger "cleantmp"
#There are multiple choices now.
#service_with_dedicated_logger "ntpd"
#service_with_dedicated_logger "ntpdate"
#service_with_dedicated_logger "openntpd"
#Obsolete now
#service_with_dedicated_logger "motd-dynamic"
service_with_dedicated_logger "network-interfaces"
service_with_dedicated_logger "network-runtime"
service_with_dedicated_logger "nisdomain"
service_with_dedicated_logger "entropy"
service_with_dedicated_logger "utx"
fan_in_logger "sysinit"
service_only "dmesg"
service_only_no_run "emergency-login@console"
service_only "hostname"
service_only "machine-id"
# Linux-specific targets, services, and sockets
service_with_dedicated_logger "kmod@ipv6"
service_with_dedicated_logger "kmod@loop"
service_with_dedicated_logger "kmod@unix"
#Not on a server
#service_with_dedicated_logger "unattended-upgrade-shutdown"
service_with_dedicated_logger "update-binfmts"
socket_with_dedicated_logger "acpid"
service_only "linux-lockfiles"
# No WantedBy or StoppedBy, so do not need to preset
#target "graphics"
#target "halt"
#target "normal"
#target "powercycle"
#target "poweroff"
#target "reboot"
#target "shutdown"
#target "unmount"
# Has StoppedBy
target "extra-shared-libraries"
target "multi-user-pre"
target "name-services"
target "normal"
# has both
target "basic"
target "dumpauto"
target "frame-buffer"
target "fs-servers"
target "local-fs"
target "local-fs-pre"
target "local-syslog"
target "multi-user"
target "reboot-after-install"
target "reboot-after-update"
target "remote-fs"
target "remote-fs-pre"
target "server"
target "static-networking"
target "swapauto"
target "swaplate"
target "sysinit"
target "users"
target "workstation"
# has both, but should not be preset
#target "finish-install"
#target "finish-update"