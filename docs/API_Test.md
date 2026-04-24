# API Architecture & Safety Standards Test Report

## 1. Route Table
| API Path | Method | Purpose | Expected Behavior |
|----------|--------|---------|-------------------|
| `/`      | GET    | Landing Page | Returns HTML with dynamic uptime |
| `/set_led?value=X` | GET | LED Control | Sets LED PWM (0-255) |

## 2. Safety Boundary Testing (Task 2)
Test cases for parameter validation and error handling.

| Test Case | Input | Expected Status | Actual Result |
|-----------|-------|-----------------|---------------|
| Missing Parameter | `/set_led` | 400 Bad Request | |
| Valid Parameter | `/set_led?value=128` | 200 OK | |
| Out of Range (High) | `/set_led?value=300` | 400 Bad Request | |
| Out of Range (Low) | `/set_led?value=-1` | 400 Bad Request | |
| Non-numeric Input | `/set_led?value=abc` | 400 Bad Request | |

## 3. Screenshots / Evidence
(Please paste screenshots of your browser or Serial Monitor here)
