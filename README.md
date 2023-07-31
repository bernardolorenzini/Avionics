> **Important notice:**
>
> This repository is intented to recreate simulationfunctionality of avionics glasscockpit.
> It's intend just for learning and not to apply in real life technologies.


<h1># Avionics</h1>

Glass Cockpit Display Software Design and Architecture


<h2>Project Overview:</h2>
    <p>
      The glass cockpit display project aims to develop a modern, user-friendly display system for a commercial aircraft, providing real-time information on power levels and the status of the two turbofan motors.
    </p>
    
<h2>System Architecture:</h2>
    <p>
      The software will be designed as a multi-layered system, utilizing the capabilities of a glass cockpit display.
    </p>
    <h3>1. Presentation Layer:</h3>
      <p>
        This layer provides a graphical user interface (GUI) for the glass cockpit display. It presents flight data and motor information in a visually appealing manner.
      </p>
      <h4>Components:</h4>
      <ul>
          <li>
              <strong>Primary Flight Display (PFD)</strong>: Displays essential flight information, such as airspeed, altitude, attitude, heading, and power levels of the motors.
          </li>
          <li>
              <strong>Engine Indication and Crew Alerting System (EICAS)</strong>: Shows detailed information about the status and power of the turbofan motors.            </li>
      </ul>
    <h3>2. Application Layer:</h3>
      <p>
        The application layer manages the data processing and logic required to compute and display motor power levels.
      </p>
      <h4>Modules:</h4>
      <ul>
          <li>
              <strong>Motor Data Processing</strong>:
              Collects and processes data from various sensors monitoring the turbofan motors.</li>
          <li>
            <strong>Motor Power Calculation</strong>: 
            Computes and updates the real-time power levels based on sensor data.</li>
      </ul>
    <h3>3. Hardware Abstraction Layer (HAL):</h3>
    <p>
      The HAL interfaces with the aircraft's data acquisition and control systems, providing a unified interface to the application layer.
    </p>
    <h4>Modules:</h4>
    <ul>
        <li>
            <strong>Data Acquisition Interface</strong>:
            Collects data from the aircraft's sensors related to the turbofan motors' performance.</li>
        <li>
            <strong>Control Interface</strong>:
            Provides commands to control the display and user interactions.</li>
    </ul>
  <h2>Design Principles:</h2>
    <ul>
        <li>
            <strong>User-Centric Design</strong>:
            The graphical interface will be intuitive, easy to read, and visually appealing to enhance pilot situational awareness.</li>
        <li>
            <strong>Real-Time Updates</strong>:
            The glass cockpit display will provide real-time updates of motor power levels, ensuring accurate and up-to-date information for the flight crew.
        </li>
        <li>
            <strong>Reliability and Redundancy</strong>:
            The software design will include redundant systems and fail-safe mechanisms to ensure reliable operation.</li>
    </ul>
  <h2>Data Flow:</h2>
    <ol>
        <li>The Data Acquisition Interface reads sensor data related to the turbofan motors' performance.</li>
        <li>The Motor Data Processing module analyzes the sensor data and prepares it for motor power calculations.</li>
        <li>The Motor Power Calculation module computes the real-time power levels of the two turbofan motors.</li>
        <li>The calculated motor power levels are sent to the Presentation Layer for display on the PFD and EICAS components.</li>
    </ol>
  <h2>Interfaces:</h2>
    <ul>
        <li>
            <strong>Data Acquisition Interface API</strong>:
            Provides functions to read sensor data related to the turbofan motors.</li>
        <li>
            <strong>Control Interface API</strong>:
            Offers functions to control the display and user interactions.</li>
    </ul>
  <h2>Assumptions:</h2>
    <ul>
        <li>The aircraft is equipped with redundant and fault-tolerant sensors for motor performance monitoring.</li>
        <li>Sensor data is accurate and within acceptable ranges for safe flight operations.</li>
    </ul>
  <h2>Compliance with DO-178C:</h2>
    <p>
      The software design and architecture will adhere to DO-178C guidelines, meeting the appropriate DAL level requirements. The plan includes thorough requirements analysis, detailed design reviews, and comprehensive verification and validation processes, ensuring compliance with aviation safety standards.
    </p>

> **Note:**
>
> As this example focuses on the glass cockpit display, it emphasizes the presentation and interaction aspects.
> In a real project, we would need to integrate this software with the aircraft's systems and ensure compliance with DO-178C DAL level requirements, including rigorous testing and certification processes.



<hr>
######### IDEIAS #########
<hr>

**Input signals:**

Engine RPM (Rotation Per Minute): Measure the rotation speed of the turbofan's engine and display it as a dynamic RPM gauge on the display. You can use a needle or a digital readout to represent the RPM value.

Thrust Level: Display the current thrust level of the engine. You can show it as a percentage or use a graphical representation like a bar graph to indicate the thrust setting.

Fuel Consumption: Show the real-time fuel consumption rate of the engine. You can display it as fuel flow rate or as the remaining fuel in the tank.

Temperature: Display the temperature of different engine components, such as turbine inlet temperature, exhaust gas temperature, and intercooler temperature.

Engine Health Parameters: Monitor engine health parameters like vibration levels, bearing temperatures, and other critical indicators. Display these values in a dashboard to provide quick insights into the engine's health status.

Air Pressure: Monitor and display the air pressure at various stages of the engine, such as compressor inlet pressure and turbine exhaust pressure.

Air-Fuel Ratio: Display the air-fuel ratio to ensure proper combustion and engine efficiency.

Engine Status and Warnings: Use visual indicators to display engine status and any warning messages related to the engine's performance or health.

Altitude and Speed: Combine engine data with other flight data like altitude and airspeed to provide a comprehensive view of the aircraft's performance.

Vibration Analysis: Analyze the engine's vibration data and display it as a spectral analysis or vibration waveform to detect any abnormal behavior.

Power Lever Position: Display the position of the power levers to provide information on the engine's power setting.

Compressor and Turbine RPM: Show the rotation speed of the compressor and turbine separately to monitor their performance.

Engine Efficiency: Calculate and display the engine's efficiency metrics, such as specific fuel consumption or overall efficiency.

Warnings and Alerts: Implement a system that displays alerts and warnings for critical events, such as exceeding certain temperature limits or low oil pressure.

Historical Data Visualization: Save and visualize historical engine data to detect trends and patterns over time, aiding in predictive maintenance.






