import { Animated, Pressable } from "react-native";
import { useTimingAnimation } from "../../hooks/useTimingAnimation";

export function AnimatedButton({ containerStyle, style, onPress, children }) {
  const {
    animation,
    in: startAnim,
    out: endAnim,
  } = useTimingAnimation({ fromValue: 1, toValue: 0.4 });

  return (
    <Animated.View style={[containerStyle, { opacity: animation }]}>
      <Pressable
        style={style}
        onPress={onPress}
        onPressIn={startAnim}
        onPressOut={endAnim}
      >
        {children}
      </Pressable>
    </Animated.View>
  );
}
