# Covid-19 Inspection Robot

An AI-powered system designed to automate Covid-19 safety checks. This project integrates face mask detection, vaccination certificate verification via QR code, and contactless temperature monitoring using an Arduino-based sensor.

## Features

- **Face Mask Detection**: Real-time detection of face masks using Deep Learning (MobileNetV2).
- **Vaccination Verification**: Scans QR codes to verify "Vaccinated" status.
- **Temperature Monitoring**: Reads body temperature using an MLX90614 sensor connected to an Arduino.
- **Voice Feedback**: Provides audio instructions and feedback to the user (e.g., "Please show vaccination card", "Temperature normal").
- **GUI Instructions**: Displays visual instructions on screen for temperature checks.

## Project Structure

```
├── Arduino/               # Arduino code for temperature sensor
├── face_detector/         # Pre-trained face detector models
├── images/                # Images for GUI and icons
├── scripts/               # Training scripts and utilities
│   └── train_mask_detector.py
├── src/                   # Source code modules
│   ├── gui.py             # GUI implementation
│   ├── speech.py          # Text-to-speech functionality
│   └── temperature.py     # Temperature checking logic
├── mask_detector.model    # Trained mask detection model
├── main.py                # Main application entry point
├── requirements.txt       # Python dependencies
└── README.md              # Project documentation
```

## Hardware Requirements

- **Camera**: Webcam for face detection and QR scanning.
- **Arduino**: Any compatible board (e.g., Uno, Nano) connected via USB.
- **Temperature Sensor**: MLX90614 contactless temperature sensor.
- **Speaker**: For audio feedback.

## Installation

1.  **Clone the repository**:
    ```bash
    git clone <repository-url>
    cd Covid-19-Inspection-Robot
    ```

2.  **Install Dependencies**:
    It is recommended to use a virtual environment.
    ```bash
    pip install -r requirements.txt
    ```

3.  **Hardware Setup**:
    - Connect the MLX90614 sensor to the Arduino.
    - Upload the code from the `Arduino` folder to your board.
    - Note the COM port (default is `COM4` in `src/temperature.py`. Update it if yours is different).

## Usage

Run the main application:

```bash
python main.py
```

### Workflow
1.  **Mask Check**: The robot scans for a face and checks for a mask.
2.  **Vaccination Check**: If a mask is detected, it asks for a vaccination card (QR Code).
3.  **Temperature Check**: If vaccinated, it prompts to check temperature via the sensor.

## Training

If you want to retrain the mask detector model:
1.  Place your dataset in `dataset/` (with `with_mask` and `without_mask` subfolders).
2.  Run:
    ```bash
    python scripts/train_mask_detector.py
    ```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)
