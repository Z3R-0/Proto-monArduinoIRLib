# Proto-monArduinoIRLib

-----------------------------NOT CURRENTLY IN WORKING STATE----------------------------

The infrared library for our school project of IR communication between 2 Arduino UNO's

THIS IS AN INFRARED PROTOCOL MEANT FOR USE BETWEEN 2 OR MORE ARDUINO'S

The protocol works by taking the data of 13 bits and modulating it with 38 or 56 kHz.
The bit/data pattern consists of:
  - 1 Start bit.
  - 5 Bits command/data.
  - 5 Bits inverse of command/data.
  - 1 Parity bit.
  - 1 Stop bit.

The IR receivers used are TSOP2138 for 38 kHz and TSOP2256 for 56 kHz.
The receivers generate an interrupt on any logical change.
2 logical changes in 2 ticks generates a logical 0.
1 logical change in 2 ticks generates a logical 1.
1 tick is equal to (1/frequency) seconds.
