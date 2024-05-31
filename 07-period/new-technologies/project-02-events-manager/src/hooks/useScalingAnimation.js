import { useRef } from "react";
import { Animated } from "react-native";

export function useScalingAnimation({ scale = 0.95 } = {}) {
  const scaleAnim = useRef(new Animated.Value(1)).current;

  const scaleIn = () => {
    Animated.timing(scaleAnim, {
      toValue: scale,
      duration: 100,
      useNativeDriver: true,
    }).start();
  };

  const scaleOut = () => {
    Animated.timing(scaleAnim, {
      toValue: 1,
      duration: 200,
      useNativeDriver: true,
    }).start();
  };

  return {
    animation: scaleAnim,
    in: scaleIn,
    out: scaleOut,
    property: "scale",
  };
}
