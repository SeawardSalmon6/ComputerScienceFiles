import styles from "@/components/Form/styles";
import React from "react";
import { Controller, useForm } from "react-hook-form";
import { View } from "react-native";

export function Form({ onFinish, children, onFieldsChange }) {
  const { watch, control, handleSubmit } = useForm();
  const fields = [];

  if (onFieldsChange) {
    watch((values) => onFieldsChange(values ?? {}));
  }

  return (
    <View style={styles.container}>
      {(Array.isArray(children) ? [...children] : [children]).map((child) => {
        const itemName = child.props.name;
        const isNewItem = itemName && !fields.includes(itemName);

        if (isNewItem) {
          fields.push(itemName);
        }

        if (itemName === "submit") {
          return React.cloneElement(child, {
            ...child.props,
            onPress: handleSubmit(onFinish),
          });
        }

        return isNewItem ? (
          <Controller
            control={control}
            name={itemName}
            render={({ field: { value, onChange } }) =>
              React.cloneElement(child, {
                ...child.props,
                key: itemName,
                value,
                onChange,
              })
            }
          />
        ) : (
          child
        );
      })}
    </View>
  );
}
