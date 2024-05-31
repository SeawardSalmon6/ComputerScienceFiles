import { APP_COLORS } from "@/assets/theme";
import styles from "@/components/Button/styles";
import { useAnimated } from "@/hooks/useAnimated.";
import { Animated, Pressable, Text } from "react-native";

export function Button({
  onPress,
  buttonStyle,
  containerStyle,
  buttonTextStyle: textStyle,
  disabled,
  children,
}) {
  const { animatedValue, onAnimationStart, onAnimationEnd } = useAnimated({
    duration: 200,
    valueFrom: 1,
    valueTo: 0.8,
  });

  return (
    <Animated.View style={[{ opacity: animatedValue }, containerStyle]}>
      <Pressable
        disabled={disabled}
        onPress={onPress}
        onPressIn={onAnimationEnd}
        onPressOut={onAnimationStart}
        style={[styles.button, disabled && styles.disabled, buttonStyle]}
      >
        <Text style={[styles.buttonText, textStyle]}>{children}</Text>
      </Pressable>
    </Animated.View>
  );
}
