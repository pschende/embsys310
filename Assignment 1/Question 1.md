BD Veritor Plus System
The BD Veritor is a hand-held diagnostic device for rapid detection of respiratory diseases. It is used to detect Influenza, RSV, Strep A, and SARS-CoV-2 from nasal swab samples. The principle of the operation is:
1. The clinician takes a sample swab and adds it to the detection buffer.
2. The detection buffer is added to the test cartridge.
3. The test cartridge is incubated for 15 minutes.
4. The Veritor device is turned on and performs a self test.
5. The test cartridge is inserted into the Veritor device.
6. The Veritor device detects the test cartridge and examines the test strip locations for positive results as well as controls and background.
7. The device determines the validity and results of the test.
8. The device displays the test results and optionally sends the results to an external network database.
9. The test cartridge is removed and the device is ready to use again.

There is little to no information on the inner workings of the device, but based on descriptions, literature, and pictures I assume that the system consists of these subsystems:
MCU
#This microcontroller stores the firmware that runs the system
Camera/test cartridge detector
#This subsystem images the test strip area of the test cartridge as well as a cartridge bar code. THe test strip area shows the test results after the incubation period. The strip is coated with antibodies in certain areas that are specific to the type of pathogen being performed as well as a positive biotin control area and a blank negative control area. Any pathogens present in the detection buffer will be bound to these sites on the test strip and labeled with detection particles (most likely fluorescent)t. A small barcode next to the test strip might contain a serial number that will indicate to the firmware the type of test and other traceable information like test lot.
Illumination source
#This light source (an LED) illuminates the test strip for readout by the detector. It is surely critical to the test results that the intensity and other optical properties of the source are calibrated. BD provides a validation test cartridge that is periodically inserted that probably serves this function.
Barcode reader
#This barcode reader can read barcodes external to the device- it is used to to read patient sample data to link to the test result. The device can also read barcodes printed in the user manual to configure the device. FOr example, the user can set the language by reading one of several barcodes in the manual.
Battery/power management
#The device is battery powered or can be used with a wall adaptor. The power management system must prevent the battery from being over or under charged.
LCD display
#The LCD display indicates to the user when the device is ready to accept a test cartridge and what the results of the test are. It can also display any relevant diagnostic information like battery level and error codes.
Multi-function button
#There is one button that can power on the device and also be used for the user interface to select the operation mode or clear messages.
Communication interface
#This interface is used to update the device's firmware and optionally communicate with an external hospital network device.

The key challenges with this device are:
Simplicity
#The test and device must be simple enough for home use as waived test under the CLIA (1988) act. The device must display all instructions, should self detect any issues that might affect test results, and allow for minimum opportunity for user error.
Reliability
#As this is an in vitro diagnostic device, both its hardware and firmware must be reliable.
Detector calibration/validation
#The device must have some way of confirming that its detector system is performing to specification. BD has supplied a specicial test cartridge that is used for this purpose.
Cartridge detection
#The test cartridge must be detected by the system and confirmed to be the correct cartridge in the correct orientation. The cartridge includes a barcode that is read internally and may be used as a fiducial marker.
Sample validation
#The test strip has areas for both positive and negative controls to validate the test results.
Cost
#The device must be cheap and simple enough to be manufactured in the millions. It is unknown whether the ~$300 price tag is sold at a profit. It could be sold at a loss as the system uses cheap single-use test cartridges that probably account for the majority of the system's profitability.
Size
#The battery, detector and control board must fit in a hand held unit.
Power consumption
#The device must run off of a single battery and may need to perform hundreds of test in between battery changes, so the unit must conserve power as much as possible.
Loss of accuracy
#The system must account for any changes to its detection system over time. The unit has a test count that limits its use to 3500 tests. I'm unsure why it has this limitation, but I'm guessing that the reliability of the tests may drop after more use.
Debugging
#The device may be debugged and reprogramed through its external communication interface, or the interface might be limited in functionality to prevent tampering. If that is the case, then it most likely only has an internal debugging interface that requires disassembly of the device. The device firmware is smart enough to complete a self test and identify what kind of cartridge test it is completing.
Hospital system communication
#The device can communicate to an external network through an optional accessory. It is paramount that this interface is secure, error free, and preserves patient data confidentiality.
