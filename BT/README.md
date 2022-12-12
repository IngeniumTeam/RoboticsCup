# BT modules configurations

## Paired modules
### Slaves

| Type | Number | ADDR             |
| ---- | ------ | ---------------- |
| S    | 01     | `98D3:61:F6B64A` |
| S    | 02     | `98D3:71:F5F110` |
| S    | 03     | `98D3:71:F653B7` |

### Masters

| Type | Number | BIND             |
| ---- | ------ | ---------------- |
| M    | 01     | `98D3:61:F6B64A` |
| M    | 02     | `98D3:71:F5F110` |
| M    | 03     | `98D3:71:F653B7` |

## Procedure
1. Choose your arduino board **Warning! Some arduino's board does not work very well: I advise you to use an official Arduino board or an ELEGOO**
2. Upload an empty sketch via the Arduino IDE
3. Wire the BT module to the arduino board following the next table:

| BT  | Arduino |
| --- | ------- |
| RXD | 0/RX    |
| TXD | 1/TX    |
| GND | GND     |
| VCC | 5V      |

4. Plug the arduino while holding down the little button on the BT module to enter in AT configuration
4. Open the serial monitor and in the bottom right of the window change `New Line` to `Both, NL & CR` and the bauds rate to `38400`
5. Now, type `AT`: the BT module should answer `OK`

### Slave
Start with the slave configuration

| Send               | Exepted answer   | Explaination                     |
| ------------------ | ---------------- | -------------------------------- |
| `AT+UART=9600,0,0` | `OK`             | Set the bauds rate of the module |
| `AT+ROLE=0`        | `OK`             | Set the module as slave          |
| `AT+ADDR`          | `****,**,******` | Get the address of the module **copy it in your notepad to keep it, you will need it** |

### Master
Configure the master to connect it to the slave

| Send                     | Exepted answer                                  | Explaination                     |
| ------------------------ | ----------------------------------------------- | -------------------------------- |
| `AT+UART=9600,0,0`       | `OK`                                            | Set the bauds rate of the module |
| `AT+ROLE=1`              | `OK`                                            | Set the module as master         |
| `AT+BIND=****,**,******` | *`Nothing, this will end the AT configuration`* | Configure the master to reach the slave's adress |