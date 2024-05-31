import { useRef } from "react";
import { Animated } from "react-native";

export function useAnimated({
  initialValue,
  valueFrom = 1,
  valueTo = 0,
  duration = 250,
} = {}) {
  const initialOptions =  { initialValue, valueFrom, valueTo, duration };
  const animatedValue = useRef(new Animated.Value(initialValue || valueFrom));

  const onAnimationStart = () => {
    Animated.timing(animatedValue.current, {
      toValue: valueFrom,
      duration: duration,
      useNativeDriver: true,
    }).start();
  };

  const onAnimationEnd = () => {
    Animated.timing(animatedValue.current, {
      toValue: valueTo,
      duration: duration,
      useNativeDriver: true,
    }).start();
  };

  return {
    animatedValue: animatedValue.current,
    onAnimationStart,
    onAnimationEnd,
    initialOptions,
  };
}
