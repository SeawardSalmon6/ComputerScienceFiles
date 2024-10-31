import { DismissKeyboard } from "@/components/DismissKeyboard";
import { getInputProps } from "@/components/Input/constants";
import styles from "@/components/Input/styles";
import { useAnimated } from "@/hooks/useAnimated.";
import { useEffect, useRef, useState } from "react";
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
  onBlur,
  codeLength = 4,
  type = "text",
  errors,
  ...props
}) {
  const [innerValue, setInnerValue] = useState("");
  const [isFocused, setIsFocused] = useState(false);
  const [shouldShowPassword, setShouldShowPassword] = useState(false);
  const codeInputRefs = Array(codeLength)
    .fill(undefined)
    .map(() => useRef(null));

  const { animatedValue, onAnimationStart, onAnimationEnd, initialOptions } =
    useAnimated({
      valueFrom: 15,
      valueTo: -10,
    });

  const shouldFloat = isFocused || innerValue.length > 0;
  const inputProps = getInputProps({ type });
  const currentIndex = innerValue.length;

  const handleFocus = () => {
    onAnimationEnd();
    setIsFocused(true);
  };

  const handleBlur = () => {
    if (onBlur) {
      onBlur();
    }

    onAnimationStart();
    setIsFocused(false);
  };

  const onKeyPress = (e) => {
    const { key } = e.nativeEvent;

    if (type === "code") {
      if (key === "Backspace") {
        if (innerValue.length <= 0) {
          return;
        }

        if (codeInputRefs[currentIndex - 1]) {
          codeInputRefs[currentIndex - 1].current.focus();
        }

        const newValue = innerValue.slice(0, -1);
        setInnerValue(newValue);

        if (onChange) {
          onChange(newValue);
        }
      }
    }
  };

  const onChangeText = (text) => {
    let newValue = text;

    if (type === "code") {
      if (innerValue.length >= codeLength) {
        return;
      }

      if (codeInputRefs[currentIndex + 1]) {
        codeInputRefs[currentIndex + 1].current.focus();
      }

      newValue = innerValue + text.replace(/[^0-9]/g, "");
    }

    setInnerValue(newValue);

    if (onChange) {
      onChange(newValue);
    }
  };

  useEffect(() => {
    if (value !== innerValue && onChange) {
      onChange(value ?? "");
      setInnerValue(value ?? "");
    }
  }, [value, innerValue]);

  if (type === "code") {
    return (
      <View style={[styles.container, styles.codeInputContainer]}>
        {Array(codeLength)
          .fill(undefined)
          .map((_, index) => (
            <KeyboardAvoidingView
              key={`code-input-${index}`}
              behavior="padding"
              style={[styles.inputContainer, styles.codeInputWrapper]}
            >
              <TextInput
                onKeyPress={onKeyPress}
                ref={codeInputRefs[index]}
                enablesReturnKeyAutomatically
                placeholder="0"
                inputMode="numeric"
                onFocus={handleFocus}
                onBlur={handleBlur}
                onEndEditing={handleBlur}
                onSubmitEditing={handleBlur}
                style={[styles.input, styles.codeInput]}
                onChangeText={onChangeText}
                maxLength={1}
                value={innerValue.charAt(index) || ""}
              />
            </KeyboardAvoidingView>
          ))}
      </View>
    );
  }

  return (
    <View style={styles.container}>
      <KeyboardAvoidingView
        behavior="padding"
        style={[
          styles.inputContainer,
          type === "password" && styles.hasSuffix,
          errors && styles.error,
        ]}
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
      {errors && <Text style={styles.errorMessage}>{errors}</Text>}
    </View>
  );
}
