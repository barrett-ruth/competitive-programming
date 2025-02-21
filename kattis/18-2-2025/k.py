import math
from scipy.optimize import minimize_scalar

def cable_length(x, L, H1, H2, d, h):
    # Calculate the height of the cable at point x
    y = H1 - (H1 - H2) * (x / L)
    
    # Ensure the rider is at least h + d meters above the ground
    if y - d < h:
        return float('inf')  # Invalid configuration
    
    # Calculate the cable length
    length1 = math.sqrt(x**2 + (H1 - y)**2)
    length2 = math.sqrt((L - x)**2 + (H2 - y)**2)
    return length1 + length2

def find_min_max_length(L, H1, H2, d, h):
    # Find the minimum length
    res_min = minimize_scalar(lambda x: cable_length(x, L, H1, H2, d, h), bounds=(0, L), method='bounded')
    min_length = res_min.fun
    
    # Find the maximum length
    res_max = minimize_scalar(lambda x: -cable_length(x, L, H1, H2, d, h), bounds=(0, L), method='bounded')
    max_length = -res_max.fun
    
    return min_length, max_length

# Example usage:
L = 1000  # Distance between poles
H1 = 100  # Height of first pole
H2 = 100  # Height of second pole
d = 20    # Distance rider hangs below cable
h = 20   # Minimum height above ground

min_length, max_length = find_min_max_length(L, H1, H2, d, h)
print(f"Minimum length: {min_length:.6f} meters")
print(f"Maximum length: {max_length:.6f} meters")
