import { DismissKeyboard } from "@/components/DismissKeyboard";
import { getInputProps } from "@/components/Input/constants";
import styles from "@/components/Input/styles";
import { useAnimated } from "@/hooks/useAnimated.";
import { useEffect, useState } from "react";
import {
  Animated,
  KeyboardAvoidingView,
  Text,
  TextInput,
  View,
} from "react-native";

export function Input({
  value,
  label,
  placeholder,
  onChange,
  type = "text",
  ...props
}) {
  const [innerValue, setInnerValue] = useState("");
  const [isFocused, setIsFocused] = useState(false);
  const [shouldShowPassword, setShouldShowPassword] = useState(false);
  const { animatedValue, onAnimationStart, onAnimationEnd, initialOptions } =
    useAnimated({
      valueFrom: 15,
      valueTo: -10,
    });

  const shouldFloat = isFocused || innerValue.length > 0;
  const inputProps = getInputProps({ type });

  const handleFocus = () => {
    onAnimationEnd();
    setIsFocused(true);
  };

  const handleBlur = () => {
    onAnimationStart();
    setIsFocused(false);
  };

  const onChangeText = (text) => {
    setInnerValue(text);
    onChange(text);
  };

  useEffect(() => {
    if (value !== innerValue) {
      onChange(value ?? "");
      setInnerValue(value ?? "");
    }
  }, [value, innerValue]);

  return (
    <View style={styles.container}>
      <KeyboardAvoidingView
        behavior="padding"
        style={[styles.inputContainer, type === "password" && styles.hasSuffix]}
      >
        <TextInput
          {...inputProps}
          enablesReturnKeyAutomatically
          onFocus={handleFocus}
          onBlur={handleBlur}
          onEndEditing={handleBlur}
          onSubmitEditing={handleBlur}
          placeholder={label ? "" : placeholder}
          style={[styles.input]}
          secureTextEntry={type === "password" && !shouldShowPassword}
          {...props}
          onChangeText={onChangeText}
          value={innerValue}
        />
        {label && (
          <Animated.View
            style={[
              styles.placeholderWrapper,
              {
                transform: [
                  {
                    translateY:
                      innerValue.length > 0
                        ? initialOptions.valueTo
                        : animatedValue,
                  },
                  { translateX: 20 },
                ],
              },
            ]}
            pointerEvents="none"
          >
            <Text
              style={[
                styles.placeholder,
                shouldFloat && styles.placeholderFloating,
              ]}
            >
              {label}
            </Text>
          </Animated.View>
        )}
        {type === "password" && (
          <Text
            style={[styles.placeholderWrapper, styles.passwordSuffix]}
            onPress={() => setShouldShowPassword(!shouldShowPassword)}
          >
            {shouldShowPassword ? "esconder" : "mostrar"}
          </Text>
        )}
      </KeyboardAvoidingView>
    </View>
  );
}
