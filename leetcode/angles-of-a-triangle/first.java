class Solution {
    public double[] findAngles(double a, double b, double c) {
        // Law of Cosines: cos(A) = (b² + c² - a²) / 2bc
        double cosA = (b * b + c * c - a * a) / (2 * b * c);
        double cosB = (a * a + c * c - b * b) / (2 * a * c);
        double cosC = (a * a + b * b - c * c) / (2 * a * b);

        // Get angles in Radians
        double angleA = Math.acos(cosA);
        double angleB = Math.acos(cosB);
        double angleC = Math.acos(cosC);

        double[] angles = {
                Math.toDegrees(Math.acos(cosA)),
                Math.toDegrees(Math.acos(cosB)),
                Math.toDegrees(Math.acos(cosC))
        };

        Arrays.sort(angles);
        return angles;
    }

    public double[] internalAngles(int[] sides) {
        if (sides[0] + sides[1] <= sides[2] || sides[1] + sides[2] <= sides[0] || sides[0] + sides[2] <= sides[1])
            return new double[] {};
        return findAngles(sides[0], sides[1], sides[2]);
    }
}