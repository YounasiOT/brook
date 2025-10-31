# Brook

Brook is an ESP32-C3 irrigation controller. It opens a valve only when a bed is drier than its line, the watering window is open, and the valve has not already run for twelve minutes. Three zero readings from the probe are treated as a disconnected sensor, and the valve stays shut.

## Check the valve rules

```bash
make test
```

## Flash

```bash
pio run -t upload
pio device monitor
```

The valve output is GPIO 4, held low at boot.
