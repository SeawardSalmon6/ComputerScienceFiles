import { useRef } from "react";
import { Animated, Easing } from "react-native";

export function useTimingAnimation({
  toValue = 0.8,
  fromValue = 1,
  duration = 200,
} = {}) {
  const timingAnim = useRef(new Animated.Value(fromValue)).current;

  const timingIn = () => {
    Animated.timing(timingAnim, {
      toValue: toValue,
      duration: duration,
      easing: Easing.ease,
      useNativeDriver: true,
    }).start();
  };

  const timingOut = () => {
    Animated.timing(timingAnim, {
      toValue: fromValue,
      duration: duration,
      easing: Easing.ease,
      useNativeDriver: true,
    }).start();
  };

  return {
    animation: timingAnim,
    in: timingIn,
    out: timingOut,
    property: "opacity",
  };
}
