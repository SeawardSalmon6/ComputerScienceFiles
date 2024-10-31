import { APP_COLORS } from "@/assets/theme";
import styles from "@/components/Slider/styles";
import { useAnimated } from "@/hooks/useAnimated.";
import { useEffect, useState } from "react";
import { Animated, Pressable } from "react-native";

export function Slider({ onChange, value, nestedButton }) {
  const [sliderValue, setSliderValue] = useState(Boolean(value));
  const { animatedValue, onAnimationEnd, onAnimationStart, initialOptions } =
    useAnimated({
      valueFrom: 0,
      valueTo: 100,
      duration: 300,
    });

  const onPress = () => {
    const newValue = !sliderValue;

    if (newValue) {
      onAnimationEnd();
    } else {
      onAnimationStart();
    }

    setSliderValue(newValue);
    if (onChange) {
      onChange(newValue);
    }
  };

  useEffect(() => {
    if (value !== sliderValue) {
      setSliderValue(Boolean(value));
    }
  }, [value, sliderValue]);

  return (
    <Pressable
      pointerEvents={nestedButton ? "none" : "auto"}
      onPress={onPress}
      style={styles.container}
    >
      <Animated.View
        style={[
          styles.slider,
          {
            backgroundColor: sliderValue
              ? APP_COLORS.darkBlue
              : APP_COLORS.blueishGray,
            transform: [
              {
                translateX: animatedValue.interpolate({
                  inputRange: [
                    initialOptions.valueFrom,
                    initialOptions.valueTo,
                  ],
                  outputRange: [8, 52],
                }),
              },
            ],
          },
        ]}
      />
    </Pressable>
  );
}
