import { Pressable, Text, TextInput, View } from "react-native";
import { styles } from "./styles";
import { AppTheme } from "../../App.theme";
import { Label } from "../Label";
import CurrencyInput from "react-native-currency-input";

export function AppTextInput({
  onChange,
  label,
  suffix,
  required = false,
  style,
  textarea = false,
  textInputProps,
  value = "",
  onPress,
  type = "text",
}) {
  return (
    <View style={styles.inputContainer}>
      <Label label={label} required={required} />
      <View style={styles.inputWrapper}>
        <Pressable onPress={onPress}>
          <View pointerEvents={onPress ? "none" : "auto"}>
            {type === "text" && (
              <TextInput
                {...textInputProps}
                style={[
                  styles.input,
                  suffix && styles.inputWithSuffix,
                  textarea && styles.textarea,
                  style,
                ]}
                placeholderTextColor={AppTheme.placeholder}
                onChangeText={onChange}
                value={value}
              />
            )}
            {type === "numeric" && (
              <CurrencyInput
                {...textInputProps}
                style={[styles.input, suffix && styles.inputWithSuffix, style]}
                placeholderTextColor={AppTheme.placeholder}
                onChangeValue={onChange}
                value={value}
              />
            )}
          </View>
        </Pressable>
        {typeof suffix === "string" ? (
          <Text style={styles.suffix}>{suffix}</Text>
        ) : (
          <View style={styles.suffix}>{suffix}</View>
        )}
      </View>
    </View>
  );
}
